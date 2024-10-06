# 변수 정의
SRCS =  ../main.cpp\
        ../4insurance/4insurance.cpp\
        ../4insurance/select1.cpp\
        ../4insurance/select2.cpp\
		../4insurance/revers_caculater.cpp\

OBJS = $(SRCS:.cpp=.o)
NAME = wandoo_emule.exe
INCLUDE = -I ../hpp -I /opt/homebrew/Cellar/sdl2/2.30.7/include -I /opt/homebrew/Cellar/sdl2_image/2.8.2_2/include
LIB = -L /opt/homebrew/Cellar/sdl2/2.30.7/lib -l SDL2 -L /opt/homebrew/Cellar/sdl2_image/2.8.2_2/lib -l SDL2_image
CFLAGS =  -g -std=c++11
RM = rm -f
CC = x86_64-w64-mingw32-g++ -static -static-libgcc -static-libstdc++  # 크로스 컴파일러로 통일

# 기본 타겟
all: ${NAME}

# 최종 실행 파일 생성 규칙
${NAME}: ${OBJS}
	${CC} ${OBJS} ${INCLUDE} ${LIB} ${CFLAGS} -o ${NAME}

# 오브젝트 파일 생성 규칙
%.o: %.cpp
	${CC} ${INCLUDE} ${CFLAGS} -c $< -o $@

# 오브젝트 파일 및 실행 파일 삭제
clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

# 재빌드 규칙
re: fclean all

# .PHONY 선언
.PHONY: all clean fclean re