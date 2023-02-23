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
#include <string>
#include <utility>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/session.hxx>
#include <odb/cache-traits.hxx>
#include <odb/polymorphic-info.hxx>
#include <odb/prepared-query.hxx>
#include <odb/result.hxx>
#include <odb/polymorphic-object-result.hxx>

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

    static const bool polymorphic = true;

    typedef ::person root_type;
    typedef ::std::string discriminator_type;
    typedef polymorphic_map<object_type> map_type;
    typedef polymorphic_concrete_info<object_type> info_type;
    typedef polymorphic_abstract_info<object_type> abstract_info_type;

    static const std::size_t depth = 1UL;

    typedef long unsigned int id_type;

    static const bool auto_id = true;

    static const bool abstract = true;

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

    static const bool polymorphic = true;

    typedef ::person root_type;
    typedef ::person base_type;
    typedef object_traits<root_type>::discriminator_type discriminator_type;
    typedef polymorphic_concrete_info<root_type> info_type;

    static const std::size_t depth = 2UL;

    typedef object_traits< ::person >::id_type id_type;

    static const bool auto_id = false;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    odb::pointer_cache_traits<
      object_traits<root_type>::pointer_type,
      odb::session >
    pointer_cache_traits;

    typedef
    odb::reference_cache_traits<
      root_type,
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

    static const bool polymorphic = true;

    typedef ::person root_type;
    typedef ::person base_type;
    typedef object_traits<root_type>::discriminator_type discriminator_type;
    typedef polymorphic_concrete_info<root_type> info_type;

    static const std::size_t depth = 2UL;

    typedef object_traits< ::person >::id_type id_type;

    static const bool auto_id = false;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    odb::pointer_cache_traits<
      object_traits<root_type>::pointer_type,
      odb::session >
    pointer_cache_traits;

    typedef
    odb::reference_cache_traits<
      root_type,
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

    // typeid_
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    typeid__type_;

    static const typeid__type_ typeid_;

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
  const typename query_columns< ::person, id_pgsql, A >::id_type_
  query_columns< ::person, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename query_columns< ::person, id_pgsql, A >::typeid__type_
  query_columns< ::person, id_pgsql, A >::
  typeid_ (A::table_name, "\"typeid\"", 0);

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
    typedef object_traits_impl<root_type, id_pgsql> root_traits;

    struct discriminator_image_type
    {
      details::buffer discriminator_value;
      std::size_t discriminator_size;
      bool discriminator_null;

      std::size_t version;
    };

    struct id_image_type
    {
      long long id_value;
      bool id_null;

      std::size_t version;
    };

    static map_type* map;
    static const abstract_info_type info;

    struct image_type
    {
      // id_
      //
      long long id_value;
      bool id_null;

      // typeid_
      //
      details::buffer typeid_value;
      std::size_t typeid_size;
      bool typeid_null;

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

      std::size_t version;
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static id_type
    id (const id_image_type&);

    static id_type
    id (const image_type&);

    static discriminator_type
    discriminator (const image_type&);

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

    typedef
    pgsql::polymorphic_root_object_statements<object_type>
    statements_type;

    typedef statements_type root_statements_type;

    typedef pgsql::query_base query_base_type;

    static const std::size_t column_count = 4UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 1UL;
    static const std::size_t managed_optimistic_column_count = 0UL;
    static const std::size_t discriminator_column_count = 1UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char find_discriminator_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&, bool top = true, bool dyn = true);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&, bool dyn = true);

    static bool
    reload (database&, object_type&, bool dyn = true);

    static void
    update (database&, const object_type&, bool top = true, bool dyn = true);

    static void
    erase (database&, const id_type&, bool top = true, bool dyn = true);

    static void
    erase (database&, const object_type&, bool top = true, bool dyn = true);

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
    static const char find_discriminator_statement_name[];
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

    static void
    discriminator_ (statements_type&,
                    const id_type&,
                    discriminator_type*);
  };

  template <>
  class access::object_traits_impl< ::person, id_common >:
    public access::object_traits_impl< ::person, id_pgsql >
  {
  };

  // employee
  //
  template <typename A>
  struct query_columns< ::employee, id_pgsql, A >:
    query_columns< ::person, id_pgsql, typename A::base_traits >
  {
    // person
    //
    typedef query_columns< ::person, id_pgsql, typename A::base_traits > person;

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

    // temporary
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        bool,
        pgsql::id_boolean >::query_type,
      pgsql::id_boolean >
    temporary_type_;

    static const temporary_type_ temporary;
  };

  template <typename A>
  const typename query_columns< ::employee, id_pgsql, A >::id_type_
  query_columns< ::employee, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename query_columns< ::employee, id_pgsql, A >::temporary_type_
  query_columns< ::employee, id_pgsql, A >::
  temporary (A::table_name, "\"temporary\"", 0);

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
    typedef polymorphic_entry<object_type, id_pgsql> entry_type;
    typedef object_traits_impl<root_type, id_pgsql> root_traits;
    typedef object_traits_impl<base_type, id_pgsql> base_traits;

    typedef root_traits::id_image_type id_image_type;

    static const info_type info;

    struct image_type
    {
      base_traits::image_type* base;

      // id_
      //
      long long id_value;
      bool id_null;

      // temporary_
      //
      bool temporary_value;
      bool temporary_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static bool
    grow (image_type&,
          bool*,
          std::size_t = depth);

    static void
    bind (pgsql::bind*,
          const pgsql::bind* id,
          std::size_t id_size,
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
          database*,
          std::size_t = depth);

    static void
    init (id_image_type&, const id_type&);

    static bool
    check_version (const std::size_t*, const image_type&);

    static void
    update_version (std::size_t*, const image_type&, pgsql::binding*);

    typedef
    pgsql::polymorphic_derived_object_statements<object_type>
    statements_type;

    typedef
    pgsql::polymorphic_root_object_statements<root_type>
    root_statements_type;

    typedef pgsql::query_base query_base_type;

    static const std::size_t column_count = 2UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char* const find_statements[depth];
    static const std::size_t find_column_counts[depth];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&, bool top = true, bool dyn = true);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&, bool dyn = true);

    static bool
    reload (database&, object_type&, bool dyn = true);

    static void
    update (database&, const object_type&, bool top = true, bool dyn = true);

    static void
    erase (database&, const id_type&, bool top = true, bool dyn = true);

    static void
    erase (database&, const object_type&, bool top = true, bool dyn = true);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    static odb::details::shared_ptr<prepared_query_impl>
    prepare_query (connection&, const char*, const query_base_type&);

    static odb::details::shared_ptr<result_impl>
    execute_query (prepared_query_impl&);

    static const char persist_statement_name[];
    static const char* const find_statement_names[depth];
    static const char update_statement_name[];
    static const char erase_statement_name[];
    static const char query_statement_name[];
    static const char erase_query_statement_name[];

    static const unsigned int persist_statement_types[];
    static const unsigned int find_statement_types[];
    static const unsigned int update_statement_types[];

    public:
    static bool
    find_ (statements_type&,
           const id_type*,
           std::size_t = depth);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload,
           std::size_t = depth);

    static void
    load_ (database&, root_type&, std::size_t);
  };

  template <>
  class access::object_traits_impl< ::employee, id_common >:
    public access::object_traits_impl< ::employee, id_pgsql >
  {
  };

  // contractor
  //
  template <typename A>
  struct query_columns< ::contractor, id_pgsql, A >:
    query_columns< ::person, id_pgsql, typename A::base_traits >
  {
    // person
    //
    typedef query_columns< ::person, id_pgsql, typename A::base_traits > person;

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
  const typename query_columns< ::contractor, id_pgsql, A >::id_type_
  query_columns< ::contractor, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

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
    typedef polymorphic_entry<object_type, id_pgsql> entry_type;
    typedef object_traits_impl<root_type, id_pgsql> root_traits;
    typedef object_traits_impl<base_type, id_pgsql> base_traits;

    typedef root_traits::id_image_type id_image_type;

    static const info_type info;

    struct image_type
    {
      base_traits::image_type* base;

      // id_
      //
      long long id_value;
      bool id_null;

      // email_
      //
      details::buffer email_value;
      std::size_t email_size;
      bool email_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static bool
    grow (image_type&,
          bool*,
          std::size_t = depth);

    static void
    bind (pgsql::bind*,
          const pgsql::bind* id,
          std::size_t id_size,
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
          database*,
          std::size_t = depth);

    static void
    init (id_image_type&, const id_type&);

    static bool
    check_version (const std::size_t*, const image_type&);

    static void
    update_version (std::size_t*, const image_type&, pgsql::binding*);

    typedef
    pgsql::polymorphic_derived_object_statements<object_type>
    statements_type;

    typedef
    pgsql::polymorphic_root_object_statements<root_type>
    root_statements_type;

    typedef pgsql::query_base query_base_type;

    static const std::size_t column_count = 2UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char* const find_statements[depth];
    static const std::size_t find_column_counts[depth];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&, bool top = true, bool dyn = true);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&, bool dyn = true);

    static bool
    reload (database&, object_type&, bool dyn = true);

    static void
    update (database&, const object_type&, bool top = true, bool dyn = true);

    static void
    erase (database&, const id_type&, bool top = true, bool dyn = true);

    static void
    erase (database&, const object_type&, bool top = true, bool dyn = true);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    static odb::details::shared_ptr<prepared_query_impl>
    prepare_query (connection&, const char*, const query_base_type&);

    static odb::details::shared_ptr<result_impl>
    execute_query (prepared_query_impl&);

    static const char persist_statement_name[];
    static const char* const find_statement_names[depth];
    static const char update_statement_name[];
    static const char erase_statement_name[];
    static const char query_statement_name[];
    static const char erase_query_statement_name[];

    static const unsigned int persist_statement_types[];
    static const unsigned int find_statement_types[];
    static const unsigned int update_statement_types[];

    public:
    static bool
    find_ (statements_type&,
           const id_type*,
           std::size_t = depth);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload,
           std::size_t = depth);

    static void
    load_ (database&, root_type&, std::size_t);
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
  // contractor
  //
}

#include "employee-odb.ixx"

#include <odb/post.hxx>

#endif // EMPLOYEE_ODB_HXX