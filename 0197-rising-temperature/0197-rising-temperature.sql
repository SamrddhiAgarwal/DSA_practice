-- # Write your MySQL query statement below
-- -- SELECT id FROM Weather WHERE ORDER BY temperature ASC GROUP BY recordDate
SELECT w2.id FROM Weather w1 JOIN Weather w2 ON DATEDIFF (w2.recordDate,w1.recordDate)=1 WHERE w2.temperature>w1.temperature 

-- SELECT w1.id
-- FROM Weather w1
-- JOIN Weather w2
-- ON DATEDIFF(w1.recordDate,w2.recordDate) = 1
-- WHERE w1.temperature > w2.temperature;