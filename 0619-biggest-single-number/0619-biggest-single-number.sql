# Write your MySQL query statement below
-- 
Select max(num) as num
from (select num 
from MyNumbers
group by num
having count(*)=1)t


-- SELECT
-- (SELECT num 
-- From MyNumbers
-- Group by num
-- Having COUNT(num)=1
-- Order by num desc LIMIT 1) As num
