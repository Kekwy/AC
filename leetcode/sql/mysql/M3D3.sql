# noinspection SqlResolveForFile

select *
from cinema
where description != 'boring' and id % 2 = 1
order by rating desc;

