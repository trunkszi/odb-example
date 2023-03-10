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
#include <odb/no-op-cache-traits.hxx>
#include <odb/prepared-query.hxx>
#include <odb/result.hxx>
#include <odb/simple-object-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // employer
  //
  template <>
  struct class_traits< ::employer >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::employer >
  {
    public:
    typedef ::employer object_type;
    typedef ::employer* pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef ::std::string id_type;

    static const bool auto_id = false;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    no_op_pointer_cache_traits<pointer_type>
    pointer_cache_traits;

    typedef
    no_op_reference_cache_traits<object_type>
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };

  // project
  //
  template <>
  struct class_traits< ::project >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::project >
  {
    public:
    typedef ::project object_type;
    typedef ::project* pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef ::std::string id_type;

    static const bool auto_id = false;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    no_op_pointer_cache_traits<pointer_type>
    pointer_cache_traits;

    typedef
    no_op_reference_cache_traits<object_type>
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
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

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    no_op_pointer_cache_traits<pointer_type>
    pointer_cache_traits;

    typedef
    no_op_reference_cache_traits<object_type>
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
  // employer
  //
  template <typename A>
  struct query_columns< ::employer, id_pgsql, A >
  {
    // name
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    name_type_;

    static const name_type_ name;
  };

  template <typename A>
  const typename query_columns< ::employer, id_pgsql, A >::name_type_
  query_columns< ::employer, id_pgsql, A >::
  name (A::table_name, "\"name\"", 0);

  template <typename A>
  struct pointer_query_columns< ::employer, id_pgsql, A >:
    query_columns< ::employer, id_pgsql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::employer, id_pgsql >:
    public access::object_traits< ::employer >
  {
    public:
    struct id_image_type
    {
      details::buffer id_value;
      std::size_t id_size;
      bool id_null;

      std::size_t version;
    };

    struct image_type
    {
      // name_
      //
      details::buffer name_value;
      std::size_t name_size;
      bool name_null;

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

    static const std::size_t column_count = 1UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
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
    static const char erase_statement_name[];
    static const char query_statement_name[];
    static const char erase_query_statement_name[];

    static const unsigned int persist_statement_types[];
    static const unsigned int find_statement_types[];

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
  class access::object_traits_impl< ::employer, id_common >:
    public access::object_traits_impl< ::employer, id_pgsql >
  {
  };

  // project
  //
  template <typename A>
  struct query_columns< ::project, id_pgsql, A >
  {
    // name
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    name_type_;

    static const name_type_ name;
  };

  template <typename A>
  const typename query_columns< ::project, id_pgsql, A >::name_type_
  query_columns< ::project, id_pgsql, A >::
  name (A::table_name, "\"name\"", 0);

  template <typename A>
  struct pointer_query_columns< ::project, id_pgsql, A >:
    query_columns< ::project, id_pgsql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::project, id_pgsql >:
    public access::object_traits< ::project >
  {
    public:
    struct id_image_type
    {
      details::buffer id_value;
      std::size_t id_size;
      bool id_null;

      std::size_t version;
    };

    struct image_type
    {
      // name_
      //
      details::buffer name_value;
      std::size_t name_size;
      bool name_null;

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

    static const std::size_t column_count = 1UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
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
    static const char erase_statement_name[];
    static const char query_statement_name[];
    static const char erase_query_statement_name[];

    static const unsigned int persist_statement_types[];
    static const unsigned int find_statement_types[];

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
  class access::object_traits_impl< ::project, id_common >:
    public access::object_traits_impl< ::project, id_pgsql >
  {
  };

  // employee
  //
  template <typename A>
  struct pointer_query_columns< ::employee, id_pgsql, A >
  {
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

    // employer
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    employer_type_;

    static const employer_type_ employer;
  };

  template <typename A>
  const typename pointer_query_columns< ::employee, id_pgsql, A >::id_type_
  pointer_query_columns< ::employee, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::employee, id_pgsql, A >::first_type_
  pointer_query_columns< ::employee, id_pgsql, A >::
  first (A::table_name, "\"first\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::employee, id_pgsql, A >::last_type_
  pointer_query_columns< ::employee, id_pgsql, A >::
  last (A::table_name, "\"last\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::employee, id_pgsql, A >::employer_type_
  pointer_query_columns< ::employee, id_pgsql, A >::
  employer (A::table_name, "\"employer\"", 0);

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

    struct image_type
    {
      // id_
      //
      long long id_value;
      bool id_null;

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

      // employer_
      //
      details::buffer employer_value;
      std::size_t employer_size;
      bool employer_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    // projects_
    //
    struct projects_traits
    {
      static const char select_name[];
      static const char insert_name[];
      static const char delete_name[];

      static const unsigned int insert_types[];

      static const std::size_t id_column_count = 1UL;
      static const std::size_t data_column_count = 2UL;

      static const bool versioned = false;

      static const char insert_statement[];
      static const char select_statement[];
      static const char delete_statement[];

      typedef ::employee::projects_type container_type;
      typedef
      odb::access::container_traits<container_type>
      container_traits_type;
      typedef container_traits_type::index_type index_type;
      typedef container_traits_type::value_type value_type;

      typedef ordered_functions<index_type, value_type> functions_type;
      typedef pgsql::container_statements< projects_traits > statements_type;

      struct data_image_type
      {
        // value
        //
        details::buffer value_value;
        std::size_t value_size;
        bool value_null;

        std::size_t version;
      };

      static void
      bind (pgsql::bind*,
            const pgsql::bind* id,
            std::size_t id_size,
            data_image_type&);

      static void
      grow (data_image_type&,
            bool*);

      static void
      init (data_image_type&,
            const value_type&);

      static void
      init (value_type&,
            const data_image_type&,
            database*);

      static void
      insert (index_type, const value_type&, void*);

      static bool
      select (index_type&, value_type&, void*);

      static void
      delete_ (void*);

      static void
      persist (const container_type&,
               statements_type&);

      static void
      load (container_type&,
            statements_type&);

      static void
      update (const container_type&,
              statements_type&);

      static void
      erase (statements_type&);
    };

    struct employer_tag;

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
  class access::object_traits_impl< ::employee, id_common >:
    public access::object_traits_impl< ::employee, id_pgsql >
  {
  };

  // employer
  //
  // project
  //
  // employee
  //
  template <>
  struct alias_traits<
    ::employer,
    id_pgsql,
    access::object_traits_impl< ::employee, id_pgsql >::employer_tag>
  {
    static const char table_name[];
  };

  template <>
  struct query_columns_base< ::employee, id_pgsql >
  {
    // employer
    //
    typedef
    odb::alias_traits<
      ::employer,
      id_pgsql,
      access::object_traits_impl< ::employee, id_pgsql >::employer_tag>
    employer_alias_;
  };

  template <typename A>
  struct query_columns< ::employee, id_pgsql, A >:
    query_columns_base< ::employee, id_pgsql >
  {
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

    // employer
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    employer_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::employer,
        id_pgsql,
        employer_alias_ > >
    employer_pointer_type_;

    struct employer_type_: employer_pointer_type_, employer_column_type_
    {
      employer_type_ (const char* t, const char* c, const char* conv)
        : employer_column_type_ (t, c, conv)
      {
      }
    };

    static const employer_type_ employer;
  };

  template <typename A>
  const typename query_columns< ::employee, id_pgsql, A >::id_type_
  query_columns< ::employee, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename query_columns< ::employee, id_pgsql, A >::first_type_
  query_columns< ::employee, id_pgsql, A >::
  first (A::table_name, "\"first\"", 0);

  template <typename A>
  const typename query_columns< ::employee, id_pgsql, A >::last_type_
  query_columns< ::employee, id_pgsql, A >::
  last (A::table_name, "\"last\"", 0);

  template <typename A>
  const typename query_columns< ::employee, id_pgsql, A >::employer_type_
  query_columns< ::employee, id_pgsql, A >::
  employer (A::table_name, "\"employer\"", 0);
}

#include "employee-odb.ixx"

#include <odb/post.hxx>

#endif // EMPLOYEE_ODB_HXX
