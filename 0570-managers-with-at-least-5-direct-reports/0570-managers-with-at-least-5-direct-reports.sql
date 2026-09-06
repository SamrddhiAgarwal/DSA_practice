# Write your MySQL query statement below
SELECT e2.name FROM Employee e1 JOIN Employee e2 ON e1.managerId=e2.Id 
GROUP BY e2.id,e2.name HAVING COUNT(*)>=5
-- when group is use instead of where having is used left join is not used since could be possible no name exist