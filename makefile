assignment: csmi928.zip

csmi928.zip: staging
	cd staging && zip -r csmi928.zip *
	mv staging/csmi928.zip .

staging: staging/assignment3_answer.pdf
	mkdir staging
	mkdir staging/task_1
	mkdir staging/task_2
	cp task_1/cachetest1.c staging/task_1/
	cp task_1/cachetest2.c staging/task_1/
	cp task_2/makefile staging/task_1/
	cp task_2/matrix1.c staging/task_2/
	cp task_2/matrix2.c staging/task_2/
	cp task_2/matrix3.c staging/task_2/
	cp task_2/makefile staging/task_2/
	mv assignment3_answer.pdf staging/
	
staging/assignment3_answer.pdf: header.md task_1/answers.md task_2/answers.md
	cat header.md task_1/answers.md task_2/answers.md > answers.cat.md
	scp answers.cat.md cam@caesium.co.nz:answers.cat.md
	echo pandoc -s -V geometry:margin=1.5in answers.cat.md -o answers.cat.pdf | ssh cam@caesium.co.nz
	scp cam@caesium.co.nz:answers.cat.pdf answers.cat.pdf
	mv answers.cat.pdf assignment3_answer.pdf
	rm answers.cat.md




clean:
	rm -rf staging
	rm csmi928.zip
	rm answers.cat.md
