# Write your MySQL query statement below

select t1.student_id, t1.student_name, t2.subject_name, count(t3.subject_name) as attended_exams
from Students t1 cross join Subjects t2 left outer join Examinations t3 on t3.student_id = t1.student_id and t3.subject_name = t2.subject_name
group by t1.student_id, t1.student_name, t2.subject_name
order by t1.student_id, t1.student_name





