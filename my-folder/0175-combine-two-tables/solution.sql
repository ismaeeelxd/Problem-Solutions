-- Write your PostgreSQL query statement below
SELECT p.firstName as firstName, p.lastName as lastName, ad.city, ad.state FROM Person AS p
LEFT JOIN Address AS ad ON p.personId = ad.personId
