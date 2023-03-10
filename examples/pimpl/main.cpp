// file      : pimpl/driver.cxx
// copyright : not copyrighted - public domain

#include <memory>   // std::shared_ptr
#include <iostream>

#include <odb/database.hxx>
#include <odb/transaction.hxx>

#include "database.h" // create_database

#include "person-odb.hxx"
#include "person.h"

using namespace std;
using namespace odb::core;

int
main (int argc, char* argv[])
{
  try
  {
    shared_ptr<database> db (create_database (argc, argv));

    {
      person john ("john@doe.com", "John Doe", 31);
      person jane ("jane@doe.com", "Jane Doe", 29);

      transaction t (db->begin ());
      db->persist (john);
      db->persist (jane);
      t.commit ();
    }

    {
      typedef odb::result<person> result;

      transaction t (db->begin ());
      result r (db->query<person> ());

      for (result::iterator i (r.begin ()); i != r.end (); ++i)
        cout << i->name () << ' ' << i->email () << ' ' << i->age () << endl;

      t.commit ();
    }
  }
  catch (const odb::exception& e)
  {
    cerr << e.what () << endl;
    return 1;
  }
}
