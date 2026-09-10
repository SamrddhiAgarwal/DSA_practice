# Write your MySQL query statement below
select max(e1.salary) as SecondHighestSalary
from Employee e1
where salary not in (select max(salary) as salary from Employee) 