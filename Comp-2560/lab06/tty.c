#include <fcntl.h>
#include <unistd.h>

void main() {
	int fd_in = open("/dev/pts/4", O_RDONLY);
	int fd_out = open("log.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	char buf[20];
	ssize_t bytes_read;
	ssize_t bytes_wrote;

	// string compare without library routine:
	char endClause[] = "END";
	int exitIfTrue = 0;

	while ((bytes_read = read(fd_in, buf, sizeof(buf))) > 0) {
		// strcmp looping and condition checking
		for (int i = 0; i < 3; i++) {
			if (buf[i] == endClause[i]) {
				exitIfTrue++;
			}
		}

		if (exitIfTrue == 3) {
			break;
		} else {
			exitIfTrue = 0;
		}
		
		bytes_wrote = write(fd_out, buf, bytes_read);
	}

	close(fd_in);
	close(fd_out);
}
