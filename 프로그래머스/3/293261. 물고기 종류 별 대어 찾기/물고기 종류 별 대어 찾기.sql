select 
    fi.id, fni.fish_name, fi.length
from
    (
        select
            A.id, B.fish_type, B.length
        from
            fish_info as A
            inner join
            (
                select fish_type, max(length) as length
                from fish_info
                group by fish_type
            ) as B
            on A.fish_type = B.fish_type and A.length = B.length
    ) as fi
    inner join
    fish_name_info as fni
    on fi.fish_type = fni.fish_type
order by fi.id asc