# Write your MySQL query statement below
-- select q.person_name
-- from
-- (select person_name,weight,turn 
-- from Queue
-- order by turn asc)q
-- where SUM(q.weight)<=1000
-- order by q.turn desc limit 1
-- this is wrong
select q.person_name
from
(select person_name,turn,SUM(weight) OVER (ORDER BY turn) AS total_weight
from Queue)q
where total_weight<=1000
order by q.turn desc limit 1
