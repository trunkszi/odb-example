/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS "person" CASCADE;

CREATE TABLE "person" (
  "email" TEXT NOT NULL PRIMARY KEY,
  "name" TEXT NOT NULL,
  "age" SMALLINT NOT NULL);

