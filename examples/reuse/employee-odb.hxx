// -*- C++ -*-
//
// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef EMPLOYEE_ODB_HXX
#define EMPLOYEE_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 20473UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "employee.h"

#include <memory>
#include <cstddef>
#include <utility>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/session.hxx>
#include <odb/cache-traits.hxx>
#include <odb/prepared-query.hxx>
#include <odb/result.hxx>
#include <odb/simple-object-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // person
  //
  template <>
  struct class_traits< ::person >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::person >
  {
    public:
    typedef ::person object_type;
    typedef ::person* pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    static const bool abstract = true;
  };

  // employee
  //
  template <>
  struct class_traits< ::employee >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::employee >
  {
    public:
    typedef ::employee object_type;
    typedef ::employee* pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef long unsigned int id_type;

    static const bool auto_id = true;

    static const bool abstract = true;

    static id_type
    id (const object_type&);
  };

  // permanent_employee
  //
  template <>
  struct class_traits< ::permanent_employee >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::permanent_employee >
  {
    public:
    typedef ::permanent_employee object_type;
    typedef ::permanent_employee* pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef object_traits< ::employee >::id_type id_type;

    static const bool auto_id = object_traits< ::employee >::auto_id;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    odb::pointer_cache_traits<
      pointer_type,
      odb::session >
    pointer_cache_traits;

    typedef
    odb::reference_cache_traits<
      object_type,
      odb::session >
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };

  // temporary_employee
  //
  template <>
  struct class_traits< ::temporary_employee >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::temporary_employee >
  {
    public:
    typedef ::temporary_employee object_type;
    typedef ::temporary_employee* pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef object_traits< ::employee >::id_type id_type;

    static const bool auto_id = object_traits< ::employee >::auto_id;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    odb::pointer_cache_traits<
      pointer_type,
      odb::session >
    pointer_cache_traits;

    typedef
    odb::reference_cache_traits<
      object_type,
      odb::session >
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };

  // contractor
  //
  template <>
  struct class_traits< ::contractor >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::contractor >
  {
    public:
    typedef ::contractor object_type;
    typedef ::contractor* pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef ::std::string id_type;

    static const bool auto_id = false;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    odb::pointer_cache_traits<
      pointer_type,
      odb::session >
    pointer_cache_traits;

    typedef
    odb::reference_cache_traits<
      object_type,
      odb::session >
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };
}

#include <odb/details/buffer.hxx>

#include <odb/pgsql/version.hxx>
#include <odb/pgsql/forward.hxx>
#include <odb/pgsql/binding.hxx>
#include <odb/pgsql/pgsql-types.hxx>
#include <odb/pgsql/query.hxx>

namespace odb
{
  // person
  //
  template <typename A>
  struct query_columns< ::person, id_pgsql, A >
  {
    // first
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    first_type_;

    static const first_type_ first;

    // last
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    last_type_;

    static const last_type_ last;
  };

  template <typename A>
  const typename query_columns< ::person, id_pgsql, A >::first_type_
  query_columns< ::person, id_pgsql, A >::
  first (A::table_name, "\"first\"", 0);

  template <typename A>
  const typename query_columns< ::person, id_pgsql, A >::last_type_
  query_columns< ::person, id_pgsql, A >::
  last (A::table_name, "\"last\"", 0);

  template <typename A>
  struct pointer_query_columns< ::person, id_pgsql, A >:
    query_columns< ::person, id_pgsql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::person, id_pgsql >:
    public access::object_traits< ::person >
  {
    public:
    struct image_type
    {
      // first_
      //
      details::buffer first_value;
      std::size_t first_size;
      bool first_null;

      // last_
      //
      details::buffer last_value;
      std::size_t last_size;
      bool last_null;
    };

    static bool
    grow (image_type&,
          bool*);

    static void
    bind (pgsql::bind*,
          image_type&,
          pgsql::statement_kind);

    static bool
    init (image_type&,
          const object_type&,
          pgsql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);
  };

  // employee
  //
  template <typename A>
  struct query_columns< ::employee, id_pgsql, A >:
    query_columns< ::person, id_pgsql, A >
  {
    // person
    //
    typedef query_columns< ::person, id_pgsql, A > person;

    // id
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        long unsigned int,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    id_type_;

    static const id_type_ id;
  };

  template <typename A>
  const typename query_columns< ::employee, id_pgsql, A >::id_type_
  query_columns< ::employee, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  struct pointer_query_columns< ::employee, id_pgsql, A >:
    query_columns< ::employee, id_pgsql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::employee, id_pgsql >:
    public access::object_traits< ::employee >
  {
    public:
    struct id_image_type
    {
      long long id_value;
      bool id_null;

      std::size_t version;
    };

    struct image_type: object_traits_impl< ::person, id_pgsql >::image_type
    {
      // id_
      //
      long long id_value;
      bool id_null;
    };

    using object_traits<object_type>::id;

    static id_type
    id (const id_image_type&);

    static id_type
    id (const image_type&);

    static bool
    grow (image_type&,
          bool*);

    static void
    bind (pgsql::bind*,
          image_type&,
          pgsql::statement_kind);

    static void
    bind (pgsql::bind*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          pgsql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);
  };

  // permanent_employee
  //
  template <typename A>
  struct query_columns< ::permanent_employee, id_pgsql, A >:
    query_columns< ::employee, id_pgsql, A >
  {
    // employee
    //
    typedef query_columns< ::employee, id_pgsql, A > employee;
  };

  template <typename A>
  struct pointer_query_columns< ::permanent_employee, id_pgsql, A >:
    query_columns< ::permanent_employee, id_pgsql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::permanent_employee, id_pgsql >:
    public access::object_traits< ::permanent_employee >
  {
    public:
    typedef object_traits_impl< ::employee, id_pgsql >::id_image_type id_image_type;

    struct image_type: object_traits_impl< ::employee, id_pgsql >::image_type
    {
      std::size_t version;
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static id_type
    id (const id_image_type&);

    static id_type
    id (const image_type&);

    static bool
    grow (image_type&,
          bool*);

    static void
    bind (pgsql::bind*,
          image_type&,
          pgsql::statement_kind);

    static void
    bind (pgsql::bind*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          pgsql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef pgsql::object_statements<object_type> statements_type;

    typedef pgsql::query_base query_base_type;

    static const std::size_t column_count = 3UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    static odb::details::shared_ptr<prepared_query_impl>
    prepare_query (connection&, const char*, const query_base_type&);

    static odb::details::shared_ptr<result_impl>
    execute_query (prepared_query_impl&);

    static const char persist_statement_name[];
    static const char find_statement_name[];
    static const char update_statement_name[];
    static const char erase_statement_name[];
    static const char query_statement_name[];
    static const char erase_query_statement_name[];

    static const unsigned int persist_statement_types[];
    static const unsigned int find_statement_types[];
    static const unsigned int update_statement_types[];

    static const std::size_t batch = 1UL;

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);
  };

  template <>
  class access::object_traits_impl< ::permanent_employee, id_common >:
    public access::object_traits_impl< ::permanent_employee, id_pgsql >
  {
  };

  // temporary_employee
  //
  template <typename A>
  struct query_columns< ::temporary_employee, id_pgsql, A >:
    query_columns< ::employee, id_pgsql, A >
  {
    // employee
    //
    typedef query_columns< ::employee, id_pgsql, A > employee;

    // duration
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        long unsigned int,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    duration_type_;

    static const duration_type_ duration;
  };

  template <typename A>
  const typename query_columns< ::temporary_employee, id_pgsql, A >::duration_type_
  query_columns< ::temporary_employee, id_pgsql, A >::
  duration (A::table_name, "\"duration\"", 0);

  template <typename A>
  struct pointer_query_columns< ::temporary_employee, id_pgsql, A >:
    query_columns< ::temporary_employee, id_pgsql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::temporary_employee, id_pgsql >:
    public access::object_traits< ::temporary_employee >
  {
    public:
    typedef object_traits_impl< ::employee, id_pgsql >::id_image_type id_image_type;

    struct image_type: object_traits_impl< ::employee, id_pgsql >::image_type
    {
      // duration_
      //
      long long duration_value;
      bool duration_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static id_type
    id (const id_image_type&);

    static id_type
    id (const image_type&);

    static bool
    grow (image_type&,
          bool*);

    static void
    bind (pgsql::bind*,
          image_type&,
          pgsql::statement_kind);

    static void
    bind (pgsql::bind*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          pgsql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef pgsql::object_statements<object_type> statements_type;

    typedef pgsql::query_base query_base_type;

    static const std::size_t column_count = 4UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    static odb::details::shared_ptr<prepared_query_impl>
    prepare_query (connection&, const char*, const query_base_type&);

    static odb::details::shared_ptr<result_impl>
    execute_query (prepared_query_impl&);

    static const char persist_statement_name[];
    static const char find_statement_name[];
    static const char update_statement_name[];
    static const char erase_statement_name[];
    static const char query_statement_name[];
    static const char erase_query_statement_name[];

    static const unsigned int persist_statement_types[];
    static const unsigned int find_statement_types[];
    static const unsigned int update_statement_types[];

    static const std::size_t batch = 1UL;

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);
  };

  template <>
  class access::object_traits_impl< ::temporary_employee, id_common >:
    public access::object_traits_impl< ::temporary_employee, id_pgsql >
  {
  };

  // contractor
  //
  template <typename A>
  struct query_columns< ::contractor, id_pgsql, A >:
    query_columns< ::person, id_pgsql, A >
  {
    // person
    //
    typedef query_columns< ::person, id_pgsql, A > person;

    // email
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    email_type_;

    static const email_type_ email;
  };

  template <typename A>
  const typename query_columns< ::contractor, id_pgsql, A >::email_type_
  query_columns< ::contractor, id_pgsql, A >::
  email (A::table_name, "\"email\"", 0);

  template <typename A>
  struct pointer_query_columns< ::contractor, id_pgsql, A >:
    query_columns< ::contractor, id_pgsql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::contractor, id_pgsql >:
    public access::object_traits< ::contractor >
  {
    public:
    struct id_image_type
    {
      details::buffer id_value;
      std::size_t id_size;
      bool id_null;

      std::size_t version;
    };

    struct image_type: object_traits_impl< ::person, id_pgsql >::image_type
    {
      // email_
      //
      details::buffer email_value;
      std::size_t email_size;
      bool email_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static id_type
    id (const image_type&);

    static bool
    grow (image_type&,
          bool*);

    static void
    bind (pgsql::bind*,
          image_type&,
          pgsql::statement_kind);

    static void
    bind (pgsql::bind*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          pgsql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef pgsql::object_statements<object_type> statements_type;

    typedef pgsql::query_base query_base_type;

    static const std::size_t column_count = 3UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, const object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    static odb::details::shared_ptr<prepared_query_impl>
    prepare_query (connection&, const char*, const query_base_type&);

    static odb::details::shared_ptr<result_impl>
    execute_query (prepared_query_impl&);

    static const char persist_statement_name[];
    static const char find_statement_name[];
    static const char update_statement_name[];
    static const char erase_statement_name[];
    static const char query_statement_name[];
    static const char erase_query_statement_name[];

    static const unsigned int persist_statement_types[];
    static const unsigned int find_statement_types[];
    static const unsigned int update_statement_types[];

    static const std::size_t batch = 1UL;

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);
  };

  template <>
  class access::object_traits_impl< ::contractor, id_common >:
    public access::object_traits_impl< ::contractor, id_pgsql >
  {
  };

  // person
  //
  // employee
  //
  // permanent_employee
  //
  // temporary_employee
  //
  // contractor
  //
}

#include "employee-odb.ixx"

#include <odb/post.hxx>

#endif // EMPLOYEE_ODB_HXX
