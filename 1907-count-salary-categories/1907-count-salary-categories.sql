-- -- # Write your MySQL query statement below
-- -- select 
-- -- case 
-- --     when income<20000 then 'Low Salary'
-- --     when income >=20000 and income<=50000 then 'Average Salary'
-- --     when income>50000 then 'High Salary'
-- --     end
-- -- as category,
-- -- sum(if(income),1,0) as accounts_merge
-- -- from Accounts
-- -- group by category
-- -- wrong
-- SELECT category, COUNT(a.account_id) AS accounts_count
-- FROM (
--     SELECT 'Low Salary' AS category
--     UNION ALL
--     SELECT 'Average Salary'
--     UNION ALL
--     SELECT 'High Salary'
-- ) categories
-- LEFT JOIN Accounts a
--     ON category =
--        CASE
--            WHEN income < 20000 THEN 'Low Salary'
--            WHEN income <= 50000 THEN 'Average Salary'
--            ELSE 'High Salary'
--        END
-- GROUP BY category;

SELECT 'Low Salary' AS category, SUM(IF(income<20000,1,0)) AS accounts_count 
FROM Accounts
UNION ALL
SELECT 'Average Salary' AS category, SUM(IF(income>=20000 AND income<=50000,1,0)) AS accounts_count 
FROM Accounts
UNION   ALL
SELECT 'High Salary' AS category, SUM(IF(income>50000,1,0)) AS accounts_count 
FROM Accounts