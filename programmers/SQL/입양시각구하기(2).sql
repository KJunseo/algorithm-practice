/*
    혼자 풀지 못했다.
    SET이라는 것과 @에 대해서 처음 알았다.
    SET @로 변수를 선언할 수 있다.
    변수를 1씩 증가시키면서 해당하는 hour의 카운트를 select 해준다.
*/
SET @hour = -1;
SELECT (@hour := @hour+1) as HOUR, 
        (SELECT COUNT(DATETIME)
        FROM ANIMAL_OUTS
        WHERE HOUR(DATETIME)=@hour) as COUNT
FROM ANIMAL_OUTS
WHERE @hour<23;