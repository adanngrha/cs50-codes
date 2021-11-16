SELECT printf("%.2f", (SUM(ratings.rating))/(COUNT(title)) - 0.01)
FROM movies
JOIN ratings ON movie_id = movies.id;