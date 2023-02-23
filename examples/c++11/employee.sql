/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS "pension_fund_members" CASCADE;

DROP TABLE IF EXISTS "pension_fund" CASCADE;

DROP TABLE IF EXISTS "employee_emails" CASCADE;

DROP TABLE IF EXISTS "employee" CASCADE;

DROP TABLE IF EXISTS "employer" CASCADE;

CREATE TABLE "employer" (
  "name" TEXT NOT NULL PRIMARY KEY);

CREATE TABLE "employee" (
  "id" BIGSERIAL NOT NULL PRIMARY KEY,
  "first" TEXT NOT NULL,
  "last" TEXT NOT NULL,
  "employer" TEXT NOT NULL,
  CONSTRAINT "employer_fk"
    FOREIGN KEY ("employer")
    REFERENCES "employer" ("name")
    INITIALLY DEFERRED);

CREATE TABLE "employee_emails" (
  "object_id" BIGINT NOT NULL,
  "value" TEXT NOT NULL,
  CONSTRAINT "object_id_fk"
    FOREIGN KEY ("object_id")
    REFERENCES "employee" ("id")
    ON DELETE CASCADE);

CREATE INDEX "employee_emails_object_id_i"
  ON "employee_emails" ("object_id");

CREATE TABLE "pension_fund" (
  "name" TEXT NOT NULL PRIMARY KEY);

CREATE TABLE "pension_fund_members" (
  "object_id" TEXT NOT NULL,
  "index" BIGINT NOT NULL,
  "value" BIGINT NOT NULL,
  CONSTRAINT "object_id_fk"
    FOREIGN KEY ("object_id")
    REFERENCES "pension_fund" ("name")
    ON DELETE CASCADE,
  CONSTRAINT "value_fk"
    FOREIGN KEY ("value")
    REFERENCES "employee" ("id")
    INITIALLY DEFERRED);

CREATE INDEX "pension_fund_members_object_id_i"
  ON "pension_fund_members" ("object_id");

CREATE INDEX "pension_fund_members_index_i"
  ON "pension_fund_members" ("index");
