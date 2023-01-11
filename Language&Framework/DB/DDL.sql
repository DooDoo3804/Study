CREATE TABLE contacts (
    name TEXT NOT NULL,
    age INT NOT NULL,
    email TEXT NOT NULL UNIQUE
);

ALTER TABLE contacts RENAME TO new_contracts;
ALTER table new_contracts RENAME COLUMN name TO last_name;
ALTER table new_contracts ADD COLUMN address TEXT NOT NULL;
ALTER table new_contracts DROP COLUMN address;
DROP TABLE new_contracts;