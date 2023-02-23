// -*- C++ -*-
//
// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

namespace odb
{
  // person
  //

  inline
  access::object_traits< ::person >::id_type
  access::object_traits< ::person >::
  id (const object_type& o)
  {
    return o.id_;
  }

  inline
  void access::object_traits< ::person >::
  callback (database& db, object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  inline
  void access::object_traits< ::person >::
  callback (database& db, const object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  // employee
  //

  inline
  access::object_traits< ::employee >::id_type
  access::object_traits< ::employee >::
  id (const object_type& o)
  {
    return object_traits< ::person >::id (o);
  }

  inline
  void access::object_traits< ::employee >::
  callback (database& db, object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  inline
  void access::object_traits< ::employee >::
  callback (database& db, const object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  // contractor
  //

  inline
  access::object_traits< ::contractor >::id_type
  access::object_traits< ::contractor >::
  id (const object_type& o)
  {
    return object_traits< ::person >::id (o);
  }

  inline
  void access::object_traits< ::contractor >::
  callback (database& db, object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  inline
  void access::object_traits< ::contractor >::
  callback (database& db, const object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }
}

#include <odb/details/unique-ptr.hxx>

namespace odb
{
  // person
  //

  inline
  void access::object_traits_impl< ::person, id_pgsql >::
  load_ (statements_type& sts,
         object_type& obj,
         bool)
  {
    ODB_POTENTIALLY_UNUSED (sts);
    ODB_POTENTIALLY_UNUSED (obj);
  }

  // employee
  //

  inline
  void access::object_traits_impl< ::employee, id_pgsql >::
  bind (pgsql::bind* b, id_image_type& i)
  {
    object_traits_impl< ::person, id_pgsql >::bind (b, i);
  }

  inline
  void access::object_traits_impl< ::employee, id_pgsql >::
  init (id_image_type& i, const id_type& id)
  {
    object_traits_impl< ::person, id_pgsql >::init (i, id);
  }

  inline
  bool access::object_traits_impl< ::employee, id_pgsql >::
  check_version (const std::size_t* v, const image_type& i)
  {
    return 
      v[0UL] != i.version ||
      v[1UL] != i.base->version;
  }

  inline
  void access::object_traits_impl< ::employee, id_pgsql >::
  update_version (std::size_t* v, const image_type& i, pgsql::binding* b)
  {
    v[0UL] = i.version;
    v[1UL] = i.base->version;
    b[0UL].version++;
    b[1UL].version++;
  }

  // contractor
  //

  inline
  void access::object_traits_impl< ::contractor, id_pgsql >::
  bind (pgsql::bind* b, id_image_type& i)
  {
    object_traits_impl< ::person, id_pgsql >::bind (b, i);
  }

  inline
  void access::object_traits_impl< ::contractor, id_pgsql >::
  init (id_image_type& i, const id_type& id)
  {
    object_traits_impl< ::person, id_pgsql >::init (i, id);
  }

  inline
  bool access::object_traits_impl< ::contractor, id_pgsql >::
  check_version (const std::size_t* v, const image_type& i)
  {
    return 
      v[0UL] != i.version ||
      v[1UL] != i.base->version;
  }

  inline
  void access::object_traits_impl< ::contractor, id_pgsql >::
  update_version (std::size_t* v, const image_type& i, pgsql::binding* b)
  {
    v[0UL] = i.version;
    v[1UL] = i.base->version;
    b[0UL].version++;
    b[1UL].version++;
  }
}

