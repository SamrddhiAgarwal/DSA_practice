-- # Write your MySQL query statement below
-- select r.requester_id as id, cnt1+cnt2 as num from
-- (select count(*) as cnt1,requester_id from RequestAccepted group by requester_id)r
-- union 
-- (select count(*) as cnt2,accepter_id from RequestAccepted group by accepter_id)a
-- on r.requester_id=a.accepter_id
-- order by num desc limit 1
# Write your MySQL query statement below
select  id, count(*) as num from
(select requester_id as id from RequestAccepted
union all 
select accepter_id as id from RequestAccepted )a
group by id
order by num desc limit 1
