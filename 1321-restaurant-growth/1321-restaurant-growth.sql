# Write your MySQL query statement below
-- pay: last 7 days (today inclusive) - avg.amt (round, 2)

SELECT visited_on, amount, ROUND(amount/7, 2) AS average_amount
FROM (
    SELECT DISTINCT visited_on,
    SUM(amount) OVER(ORDER BY visited_on RANGE BETWEEN INTERVAL 6 DAY PRECEDING AND CURRENT ROW) AS amount,
    -- SUM(amount) OVER(ORDER BY visited_on rows BETWEEN  6 PRECEDING AND CURRENT ROW) AS amount, doesn't5 work here since  it will go by 6 rows only not range 
    MIN(visited_on) OVER() as day_1
    FROM Customer
) t
-- WHERE visited_on >= day_1+6;
WHERE visited_on >= DATE_ADD(day_1, INTERVAL 6 DAY);




-- -- if wan to use roews between then need to group date
-- SELECT
--     visited_on,
--     amount,
--     ROUND(amount / 7, 2) AS average_amount
-- FROM (
--     SELECT
--         visited_on,

--         SUM(daily_amount) OVER (
--             ORDER BY visited_on
--             ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
--         ) AS amount,

--         MIN(visited_on) OVER () AS day_1

--     FROM (
--         SELECT
--             visited_on,
--             SUM(amount) AS daily_amount
--         FROM Customer
--         GROUP BY visited_on
--     ) d
-- ) t
-- WHERE visited_on >= DATE_ADD(day_1, INTERVAL 6 DAY);
