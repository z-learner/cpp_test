#include <boost/atomic.hpp>
#include <boost/intrusive_ptr.hpp>
#include <boost/memory_order.hpp>


template <class T>
class ref_count {

private:
  typedef boost::atomic<int> atomic_type;
  mutable atomic_type m_count{0};
protected:
  ref_count() {}
  ~ref_count() {}
public:
  typedef boost::intrusive_ptr<T> counted_ptr;

  void add_ref() const {
    m_count.fetch_add(1, boost::memory_order_relaxed); // no order require
  }

  void sub_ref() const {
    if (m_count.fetch_sub(1, boost::memory_order_release) == 1) {
      delete static_cast<const T*>(this);
    }
  }

public:
  template<typename ...Args>
  static counted_ptr make_ptr(Args&& ...args) {
    return counted_ptr(new T(std::forward<Args>(args)...));
  }

  decltype(m_count.load()) count() const {
    return m_count.load();
  } 
private:
  friend void intrusive_ptr_add_ref(const T* p) {
    p->add_ref();
  }

  friend void intrusive_ptr_release(const T* p) {
    p->sub_ref();
  }

};