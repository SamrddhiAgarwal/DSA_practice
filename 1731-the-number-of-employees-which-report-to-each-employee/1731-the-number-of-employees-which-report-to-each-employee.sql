# Write your MySQL query statement below
select e1.employee_id,e1.name,count(*) as reports_count,round(avg(e2.age),0) as average_age
from Employees e2 join Employees e1
on e2.reports_to =e1.employee_id
group by e1.employee_id
order by e1.employee_id
