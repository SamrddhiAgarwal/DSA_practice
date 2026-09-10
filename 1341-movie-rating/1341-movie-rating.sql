# Write your MySQL query statement below
(
select name as results
from Users u right join MovieRating r
on u.user_id=r.user_id
group by r.user_id
order by count(*) desc , u.name asc limit 1
)
union all
(
select title as results
from Movies m right join MovieRating r
on m.movie_id=r.movie_id 
-- where r.created_at>='2020-02-01' and r.created_at<='2020-02-29' this is also crrect
WHERE DATE_FORMAT(created_at, '%Y-%m') = '2020-02'
group by r.movie_id
order by avg(r.rating) desc , m.title asc limit 1 )