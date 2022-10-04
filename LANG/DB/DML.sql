CREATE TABLE users (
    first_name TEXT NOT NULL,
    last_name TEXT NOT NULL,
    age INT NOT NULL,
    country TEXT NOT NULL,
    phone TEXT NOT NULL,
    balance INT NOT NULL
);

SELECT first_name, age FROM users;

SELECT first_name, age, balance FROM users
ORDER BY age ASC, balance DESC;

SELECT country FROM users;
SELECT DISTINCT country FROM users;

SELECT first_name, age FROM users WHERE age >= 30;

SELECT first_name last_name FROM users WHERE first_name LIKE '%호%';