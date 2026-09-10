# Write your MySQL query statement below
-- select max(e1.salary) as SecondHighestSalary
-- from Employee e1
-- where salary not in (select max(salary) as salary from Employee) 

-- method 2
SELECT (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1
) AS SecondHighestSalary;
