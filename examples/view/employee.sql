/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS "employee" CASCADE;

DROP TABLE IF EXISTS "employer" CASCADE;

DROP TABLE IF EXISTS "country" CASCADE;

CREATE TABLE "country" (
  "code" TEXT NOT NULL PRIMARY KEY,
  "name" TEXT NOT NULL);

CREATE TABLE "employer" (
  "id" BIGINT NOT NULL PRIMARY KEY,
  "name" TEXT NOT NULL);

CREATE TABLE "employee" (
  "id" BIGINT NOT NULL PRIMARY KEY,
  "first" TEXT NOT NULL,
  "last" TEXT NOT NULL,
  "age" SMALLINT NOT NULL,
  "residence" TEXT NULL,
  "nationality" TEXT NULL,
  "employed_by" BIGINT NULL,
  CONSTRAINT "residence_fk"
    FOREIGN KEY ("residence")
    REFERENCES "country" ("code")
    INITIALLY DEFERRED,
  CONSTRAINT "nationality_fk"
    FOREIGN KEY ("nationality")
    REFERENCES "country" ("code")
    INITIALLY DEFERRED,
  CONSTRAINT "employed_by_fk"
    FOREIGN KEY ("employed_by")
    REFERENCES "employer" ("id")
    INITIALLY DEFERRED);
