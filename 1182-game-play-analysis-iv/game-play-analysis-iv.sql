# Write your MySQL query statement below


select round(count(distinct a.player_id)*1.0/(select count(distinct player_id) from Activity), 2) as fraction
from Activity a
join (
    select player_id, min(event_date) as first_login
    from Activity 
    group by player_id
) b
on a.player_id = b.player_id
where a.event_date = DATE_ADD(b.first_login, INTERVAL 1 DAY); 
