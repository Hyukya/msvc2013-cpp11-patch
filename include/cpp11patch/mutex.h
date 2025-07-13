#ifndef CPP11PATCH_MUTEX_H
#define CPP11PATCH_MUTEX_H

#if defined(_MSC_VER) && (_MSC_VER <= 1800)  // For MSVC2013 and earlier
#include <mutex>
#include <atomic>
#include <utility>

namespace cpp11patch {

struct once_flag {
    std::mutex mtx_;
    std::atomic<bool> initialized_{false};

    once_flag() = default;
    once_flag(const once_flag&) = delete;
    once_flag& operator=(const once_flag&) = delete;
};

// Custom call_once implementation for MSVC2013 and earlier
template <class Callable, class... Args>
void call_once(once_flag& flag, Callable&& f, Args&&... args) {
    if (!flag.initialized_.load(std::memory_order_acquire)) {
        std::lock_guard<std::mutex> lock(flag.mtx_);
        if (!flag.initialized_.load(std::memory_order_relaxed)) {
            std::forward<Callable>(f)(std::forward<Args>(args)...);
            flag.initialized_.store(true, std::memory_order_release);
        }
    }
}

} // namespace cpp11patch

#else  // For modern compilers, use the standard library
#include <mutex>

namespace cpp11patch {
    using std::once_flag;
    using std::call_once;
}

#endif // MSVC version check

#endif // CPP11PATCH_MUTEX_H
