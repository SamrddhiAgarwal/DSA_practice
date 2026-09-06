# Write your MySQL query statement below
SELECT s.user_id,
    ROUND(
        COALESCE(SUM(c.action='confirmed')/COUNT(*),0)
        ,2) 
    AS confirmation_rate
FROM Signups s LEFT JOIN Confirmations c
ON s.user_id=c.user_id
GROUP BY s.user_id
-- sum is used instaed of count since = will give 1 and 0 values leadig to count of zeroes also 
-- coalesce is used as coalesce(null,val1,val2,null) returns first val which is not null as here val1 
-- method-2 
    -- IFNULL(
    --     ROUND(
    --             COUNT(CASE WHEN 
    --                 c.action = 'confirmed' THEN 1 
    --                 END
    --             ) 
    --             / COUNT(c.action), 
    --         2
    --     ), 
    --     0
    -- )
    -- instead of count can use avg