-- -- -- # Write your MySQL query statement below
-- -- -- select s1.id , s2.student
-- -- -- from Seat s1 join Seat s2
-- -- -- on 
-- -- -- case when id%2=1 then s1.id=s2.id+1;
-- -- -- else s1.id=s2.id-1
-- -- -- end 
-- -- -- it is wrong
-- -- SELECT
-- --     s1.id,
-- --     s2.student
-- -- FROM Seat s1
-- -- JOIN Seat s2
-- --     ON (
-- --         s1.id % 2 = 1 AND s2.id = s1.id + 1
-- --     )
-- --     OR (
-- --         s1.id % 2 = 0 AND s2.id = s1.id - 1
-- --     );
-- --  this is also wrong 
-- SELECT new_id AS id, student
-- FROM (
--     SELECT
--         CASE
--             WHEN id % 2 = 1 AND id = (SELECT MAX(id) FROM Seat)
--                 THEN id
--             WHEN id % 2 = 1
--                 THEN id + 1
--             ELSE id - 1
--         END AS new_id,
--         student
--     FROM Seat
-- ) t
-- ORDER BY id;
-- id, student
-- swap every two consecutives
-- num(students): odd? no swap for last one

SELECT id, 
CASE WHEN MOD(id,2)=0 THEN (LAG(student) OVER (ORDER BY id))
ELSE (LEAD(student, 1, student) OVER (ORDER BY id))
END AS 'Student'
FROM Seat
-- LEAD(column, offset, default)