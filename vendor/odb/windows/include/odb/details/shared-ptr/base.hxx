// file      : odb/details/shared-ptr/base.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_SHARED_PTR_BASE_HXX
#define ODB_DETAILS_SHARED_PTR_BASE_HXX

#include <odb/pre.hxx>

#include <odb/details/config.hxx> // ODB_CXX11, ODB_NOTHROW_NOEXCEPT

#include <new>
#include <cstddef>   // std::size_t

#ifdef ODB_CXX11
#include <atomic>
#endif

#include <odb/details/export.hxx>
#include <odb/details/shared-ptr/counter-type.hxx>

namespace odb
{
  namespace details
  {
    struct share
    {
      explicit
      share (char id);

      bool
      operator== (share) const;

    private:
      char _id;
    };

    extern LIBODB_EXPORT share shared;
    extern LIBODB_EXPORT share exclusive;
  }
}

#ifdef ODB_CXX11
LIBODB_EXPORT void*
operator new (std::size_t, odb::details::share);
#else
LIBODB_EXPORT void*
operator new (std::size_t, odb::details::share) throw (std::bad_alloc);
#endif

LIBODB_EXPORT void
operator delete (void*, odb::details::share) ODB_NOTHROW_NOEXCEPT;

namespace odb
{
  namespace details
  {
    class LIBODB_EXPORT shared_base
    {
    public:
      shared_base ();
      shared_base (const shared_base&);
      shared_base&
      operator= (const shared_base&);

      void
      _inc_ref ();

      bool
      _dec_ref ();

      std::size_t
      _ref_count () const;

#ifdef ODB_CXX11
      void*
      operator new (std::size_t);

      void*
      operator new (std::size_t, share);
#else
      void*
      operator new (std::size_t) throw (std::bad_alloc);

      void*
      operator new (std::size_t, share) throw (std::bad_alloc);
#endif

      void
      operator delete (void*, share) ODB_NOTHROW_NOEXCEPT;

      void
      operator delete (void*) ODB_NOTHROW_NOEXCEPT;

      struct refcount_callback
      {
        void* arg;

        // Return true if the object should be deleted, false otherwise.
        //
        bool (*zero_counter) (void*);
      };

    protected:
#ifdef ODB_CXX11
      std::atomic<std::size_t> counter_;
#else
      std::size_t counter_;
#endif
      refcount_callback* callback_;
    };

    template <typename X>
    inline X*
    inc_ref (X*);

    template <typename X>
    inline void
    dec_ref (X*);

    template <typename X>
    inline std::size_t
    ref_count (const X*);
  }
}

#include <odb/details/shared-ptr/base.ixx>
#include <odb/details/shared-ptr/base.txx>

#include <odb/post.hxx>

#endif // ODB_DETAILS_SHARED_PTR_BASE_HXX
