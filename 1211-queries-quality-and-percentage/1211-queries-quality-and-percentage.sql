# Write your MySQL query statement below
-- select distinct  query_name, 
select query_name, 
    -- avg(rating/position) as quality ,
    round(avg(rating/position),2) as quality ,
    round( count(case when rating <3 then 1 end)/count(*) * 100 ,2)  as poor_query_percentage
from Queries
group by query_name


-- SELECT
--     query_name,
--     ROUND(AVG(rating / position), 2) AS quality
-- FROM (
--     SELECT DISTINCT query_name, rating, position
--     FROM Queries
-- ) q
-- GROUP BY query_name;
-- if was need to remove dupliacye rows