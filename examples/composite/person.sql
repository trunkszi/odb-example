/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS "person_name_extras_aliases" CASCADE;

DROP TABLE IF EXISTS "person" CASCADE;

CREATE TABLE "person" (
  "email_recipient" TEXT NOT NULL,
  "email_domain" TEXT NOT NULL,
  "name_first" TEXT NOT NULL,
  "name_last" TEXT NOT NULL,
  "name_title" TEXT NOT NULL,
  "name_extras_nickname" TEXT NOT NULL,
  "phone_first" TEXT NOT NULL,
  "phone_second" TEXT NOT NULL,
  PRIMARY KEY ("email_recipient",
               "email_domain"));

CREATE TABLE "person_name_extras_aliases" (
  "object_id_recipient" TEXT NOT NULL,
  "object_id_domain" TEXT NOT NULL,
  "index" BIGINT NOT NULL,
  "value_first" TEXT NOT NULL,
  "value_last" TEXT NOT NULL,
  CONSTRAINT "object_id_fk"
    FOREIGN KEY ("object_id_recipient",
                 "object_id_domain")
    REFERENCES "person" ("email_recipient",
                         "email_domain")
    ON DELETE CASCADE);

CREATE INDEX "person_name_extras_aliases_object_id_i"
  ON "person_name_extras_aliases" (
    "object_id_recipient",
    "object_id_domain");

CREATE INDEX "person_name_extras_aliases_index_i"
  ON "person_name_extras_aliases" ("index");
