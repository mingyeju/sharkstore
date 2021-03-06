_Pragma("once");

#include <chrono>

#include "raft.pb.h"
#include "raft_types.h"

namespace fbase {
namespace raft {
namespace impl {

class Inflight {
public:
    explicit Inflight(int max);

    Inflight(const Inflight&) = delete;
    Inflight& operator=(const Inflight&) = delete;

    void add(uint64_t index);
    void freeTo(uint64_t index);
    void freeFirstOne();
    bool full() const;
    void reset();

private:
    const int capacity_ = 0;        // 循环buffer的大小
    std::vector<uint64_t> buffer_;  // 循环buffer
    int start_ = 0;
    int count_ = 0;
};

class Replica {
public:
    Replica(const pb::Peer& peer, int max_inflight);
    ~Replica() = default;

    Replica(const Replica&) = delete;
    Replica& operator=(const Replica&) = delete;

    const pb::Peer& peer() const { return peer_; }
    void set_peer(const pb::Peer& peer) { peer_ = peer; }

    Inflight& inflight() { return inflight_; }

    uint64_t next() const { return next_; }
    void set_next(uint64_t next) { next_ = next; }

    uint64_t match() const { return match_; }
    void set_match(uint64_t match) { match_ = match; }

    uint64_t committed() const { return committed_; }
    void set_committed(uint64_t committed) { committed_ = committed; }

    // 设置为活跃的
    bool active() const { return active_; }
    void set_active();
    int inactive_seconds() const;

    ReplicaState state() const { return state_; }
    void resetState(ReplicaState state);
    void becomeProbe();
    void becomeReplicate();
    void becomeSnapshot(uint64_t index);

    void update(uint64_t index);
    bool maybeUpdate(uint64_t index, uint64_t commit);
    bool maybeDecrTo(uint64_t rejected, uint64_t last, uint64_t commit);

    void snapshotFailure();
    bool needSnapshotAbort();

    void pause();
    void resume();
    bool isPaused() const;

    bool pending() const { return pending_; }
    void set_pending(bool b) { pending_ = b; }

    std::string ToString() const;

private:
    typedef std::chrono::time_point<std::chrono::steady_clock> TimePoint;

    pb::Peer peer_;
    ReplicaState state_{ReplicaState::kProbe};
    Inflight inflight_;

    bool paused_ = false;
    bool pending_ = false;
    bool active_ = false;
    TimePoint last_active_;

    uint64_t match_ = 0;
    uint64_t next_ = 0;
    uint64_t committed_ = 0;
    uint64_t pendingSnap_ = 0;
};

} /* namespace impl */
} /* namespace raft */
} /* namespace fbase */
