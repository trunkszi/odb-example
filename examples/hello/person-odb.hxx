// -*- C++ -*-
//
// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef PERSON_ODB_HXX
#define PERSON_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 20473UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "person.h"

#include <memory>
#include <cstddef>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/no-op-cache-traits.hxx>
#include <odb/result.hxx>
#include <odb/simple-object-result.hxx>
#include <odb/view-image.hxx>
#include <odb/view-result.hxx>

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

  // person_stat
  //
  template <>
  struct class_traits< ::person_stat >
  {
    static const class_kind kind = class_view;
  };

  template <>
  class access::view_traits< ::person_stat >
  {
    public:
    typedef ::person_stat view_type;
    typedef ::person_stat* pointer_type;

    static void
    callback (database&, view_type&, callback_event);
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

    // age
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        short unsigned int,
        pgsql::id_smallint >::query_type,
      pgsql::id_smallint >
    age_type_;

    static const age_type_ age;
  };

  template <typename A>
  const typename query_columns< ::person, id_pgsql, A >::id_type_
  query_columns< ::person, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename query_columns< ::person, id_pgsql, A >::first_type_
  query_columns< ::person, id_pgsql, A >::
  first (A::table_name, "\"first\"", 0);

  template <typename A>
  const typename query_columns< ::person, id_pgsql, A >::last_type_
  query_columns< ::person, id_pgsql, A >::
  last (A::table_name, "\"last\"", 0);

  template <typename A>
  const typename query_columns< ::person, id_pgsql, A >::age_type_
  query_columns< ::person, id_pgsql, A >::
  age (A::table_name, "\"age\"", 0);

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

      // age_
      //
      short age_value;
      bool age_null;

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
  class access::object_traits_impl< ::person, id_common >:
    public access::object_traits_impl< ::person, id_pgsql >
  {
  };

  // person_stat
  //
  template <>
  class access::view_traits_impl< ::person_stat, id_pgsql >:
    public access::view_traits< ::person_stat >
  {
    public:
    struct image_type
    {
      // count
      //
      long long count_value;
      bool count_null;

      // min_age
      //
      short min_age_value;
      bool min_age_null;

      // max_age
      //
      short max_age_value;
      bool max_age_null;

      std::size_t version;
    };

    typedef pgsql::view_statements<view_type> statements_type;

    typedef pgsql::query_base query_base_type;
    struct query_columns;

    static const bool versioned = false;

    static bool
    grow (image_type&,
          bool*);

    static void
    bind (pgsql::bind*,
          image_type&);

    static void
    init (view_type&,
          const image_type&,
          database*);

    static const std::size_t column_count = 3UL;

    static query_base_type
    query_statement (const query_base_type&);

    static result<view_type>
    query (database&, const query_base_type&);

    static const char query_statement_name[];
  };

  template <>
  class access::view_traits_impl< ::person_stat, id_common >:
    public access::view_traits_impl< ::person_stat, id_pgsql >
  {
  };

  // person
  //
  // person_stat
  //
  struct access::view_traits_impl< ::person_stat, id_pgsql >::query_columns:
    odb::pointer_query_columns<
      ::person,
      id_pgsql,
      odb::access::object_traits_impl< ::person, id_pgsql > >
  {
  };
}

#include "person-odb.ixx"

#include <odb/post.hxx>

#endif // PERSON_ODB_HXX
