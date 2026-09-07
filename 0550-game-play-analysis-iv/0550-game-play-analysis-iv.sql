-- # Write your MySQL query statement below
-- select 
--     -- round( count(case when datediff(a1.event_date,a2.event_date)=1) then 1) / count(*),2)
--     round( count(case when datediff(a1.event_date,a2.event_date)=1 then 1 end) / 
--     (select count(distinct player_id) from Activity),2)
--     from Activity a1 Left join Activity a2
--     where player_id,event_date in( 
--         select event_date 
--         from Activity 
--         min(event_date))
--         group by player_id 
--         )
--         on a1.player_id=a2.player_id
SELECT
    ROUND(
        -- COUNT(DISTINCT CASE
        --     WHEN DATEDIFF(a.event_date, f.first_date) = 1
        --     THEN a.player_id
        -- END)
        -- COUNT( CASE
        --     WHEN DATEDIFF(a.event_date, f.first_date) = 1
        --     THEN 1
        -- END)
        COUNT(a.event_date)
        / COUNT(DISTINCT f.player_id),
        2
    ) AS fraction
FROM (
    SELECT player_id, MIN(event_date) AS first_date
    FROM Activity
    GROUP BY player_id
) f
LEFT JOIN Activity a
    ON a.player_id = f.player_id
   AND DATEDIFF(a.event_date, f.first_date) = 1;