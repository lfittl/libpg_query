const char* tests[] = {
  "SELECT 1",
  "c942134af8b79019",
  "SELECT 2",
  "c942134af8b79019",
  "SELECT ?",
  "c942134af8b79019",
  "SELECT $1",
  "c942134af8b79019",
  "SELECT 1; SELECT a FROM b",
  "3deaf6796312bb07",
  "SELECT COUNT(DISTINCT id), * FROM targets WHERE something IS NOT NULL AND elsewhere::interval < now()",
  "63a62d6fad16bb8c",
  "INSERT INTO test (a, b) VALUES (?, ?)",
  "8b0f05e18fbf2f4e",
  "INSERT INTO test (b, a) VALUES (?, ?)",
  "8b0f05e18fbf2f4e",
  "INSERT INTO test (a, b) VALUES (ARRAY[?, ?, ?, ?], ?::timestamptz), (ARRAY[?, ?, ?, ?], ?::timestamptz), (?, ?::timestamptz)",
  "f606f678d3dfe691",
  "SELECT b AS x, a AS y FROM z",
  "e56148351256d4ab",
  "SELECT * FROM x WHERE y = ?",
  "b3c510580a1f2e76",
  "SELECT * FROM x WHERE y IN (?)",
  "6d34bed1b3fea42a",
  "SELECT * FROM x WHERE y IN (?, ?, ?)",
  "6d34bed1b3fea42a",
  "SELECT * FROM x WHERE y IN ( ?::uuid )",
  "2989935d734051f7",
  "SELECT * FROM x WHERE y IN ( ?::uuid, ?::uuid, ?::uuid )",
  "2989935d734051f7",
  "PREPARE a123 AS SELECT a",
  "988408394bc6f04f",
  "EXECUTE a123",
  "96a278eb57911531",
  "DEALLOCATE a123",
  "c2cb89426e2ec9c5",
  "DEALLOCATE ALL",
  "c2cb89426e2ec9c5",
  "EXPLAIN ANALYZE SELECT a",
  "619d6054f2bd5697",
  "WITH a AS (SELECT * FROM x WHERE x.y = ? AND x.z = 1) SELECT * FROM a",
  "2aa34dae695a788b",
  "CREATE TABLE types (a float(2), b float(49), c NUMERIC(2, 3), d character(4), e char(5), f varchar(6), g character varying(7))",
  "d33a657b1cd18f2",
  "CREATE VIEW view_a (a, b) AS WITH RECURSIVE view_a (a, b) AS (SELECT * FROM a(1)) SELECT \"a\", \"b\" FROM \"view_a\"",
  "787ca36a5005c2d1",
  "VACUUM FULL my_table",
  "85bf5c1e833ced66",
  "SELECT * FROM x AS a, y AS b",
  "604f7f39b075ad34",
  "SELECT * FROM y AS a, x AS b",
  "604f7f39b075ad34",
  "SELECT x AS a, y AS b FROM x",
  "1d048a36d9a94e21",
  "SELECT y AS a, x AS b FROM x",
  "1d048a36d9a94e21",
  "SELECT x, y FROM z",
  "f455825b309a99b1",
  "SELECT y, x FROM z",
  "f455825b309a99b1",
  "INSERT INTO films (code, title, did) VALUES ('UA502', 'Bananas', 105), ('T_601', 'Yojimbo', DEFAULT)",
  "3bf37e9d5681413b",
  "INSERT INTO films (code, title, did) VALUES (?, ?, ?)",
  "3bf37e9d5681413b",
  "SELECT * FROM a",
  "bd4080ad382c77fe",
  "SELECT * FROM a AS b",
  "bd4080ad382c77fe",
  "UPDATE users SET one_thing = $1, second_thing = $2 WHERE users.id = ?",
  "545ade19933716fe",
  "UPDATE users SET something_else = $1 WHERE users.id = ?",
  "bd8553a7a106574e",
  "UPDATE users SET something_else = (SELECT a FROM x WHERE uid = users.id LIMIT 1) WHERE users.id = ?",
  "e5fc231ac31558e2",
  "SAVEPOINT some_id",
  "84e8d812964e82f2",
  "RELEASE some_id",
  "23d41dd4d944b285",
  "PREPARE TRANSACTION 'some_id'",
  "d579d8e209d6d407",
  "START TRANSACTION READ WRITE",
  "82372a10e9653107",
  "DECLARE cursor_123 CURSOR FOR SELECT * FROM test WHERE id = 123",
  "cffd92a65c869a81",
  "FETCH 1000 FROM cursor_123",
  "184614d8121617d2",
  "CLOSE cursor_123",
  "330782901738d43f",
  "-- nothing",
  "3a20f67fd6abb44e",
  "CREATE FOREIGN TABLE ft1 () SERVER no_server",
  "f1f23e87863d7077",
  "UPDATE x SET a = 1, b = 2, c = 3",
  "e054cd967d5a17ba",
  "UPDATE x SET z = now()",
  "ab54e9c98d36fa1",
  "CREATE TEMPORARY TABLE my_temp_table (test_id integer NOT NULL) ON COMMIT DROP",
  "38856e2019f1466b",
  "CREATE TEMPORARY TABLE my_temp_table AS SELECT 1",
  "4e9716c8bbe1c11d",
  "SELECT INTERVAL (0) $2",
  "aaefe64bc05dcfe0",
  "SELECT INTERVAL (2) $2",
  "aaefe64bc05dcfe0",
};

size_t testsLength = __LINE__ - 4;
