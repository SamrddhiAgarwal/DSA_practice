-- # Write your MySQL query statement below
-- select employee_id ,department_id
-- from Employee e
-- where e.primary_flag='Y'
-- or
-- (employee_id,department_id) in
-- (select employee_id, department_id
-- from Employees
-- group by employee_id
-- having count(*)=1)
SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y'

UNION

SELECT employee_id, department_id
FROM Employee
GROUP BY employee_id
HAVING COUNT(*) = 1;