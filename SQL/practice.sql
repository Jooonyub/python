SELECT title
FROM people
JOIN stars ON people.id = stars.person_id
JOIN shows ON stars.show_id = shows.id
WHERE name = "Ellen DeGeneres";

people과 stars를 쪼인(people.id = stars.person_id)
이걸 shows와 쪼인(stars.show_id = shows.id)