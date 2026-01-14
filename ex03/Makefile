# --- Colors ---
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BOLD    = \033[1m
RESET   = \033[0m
CLEAR   = \033[2K\r

# --- Binary ---
NAME = a.out

# --- Compiler ---
CXX = c++

# --- Flags ---
STD      = -std=c++98
WARN     = -g3 -Wall -Wextra -Werror
DEBUGFLG = -g -O0
SANITIZE = -fsanitize=address,undefined

CXXFLAGS = $(WARN) $(STD)
DBGFLAGS = $(WARN) $(STD) $(DEBUGFLG) $(SANITIZE)
LDFLAGS  =
DBGLINK  = $(SANITIZE)

# --- Includes ---
INCLUDES = -I.

# --- Sources ---
SRC = MateriaSource.cpp AMateria.cpp Character.cpp Cure.cpp Floor.cpp Ice.cpp minitest.cpp
OBJ = $(SRC:%.cpp=obj/%.o)
DBGOBJ = $(SRC:%.cpp=obj/debug/%.o)

# =========================
#        RULES
# =========================

all: $(NAME)
	@printf "$(GREEN)$(BOLD)$(NAME) done!$(RESET)\n"

debug: $(DBGOBJ)
	@printf "$(CLEAR)$(YELLOW)linking $(NAME) [debug]...$(RESET)\n"
	@$(CXX) $(DBGOBJ) $(DBGLINK) -o $(NAME)
	@printf "$(GREEN)$(BOLD)$(NAME) debug done!$(RESET)\n"

# --- Normal build ---
$(NAME): $(OBJ)
	@printf "$(CLEAR)$(YELLOW)linking $(NAME)...$(RESET)\n"
	@$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

obj/%.o: %.cpp
	@mkdir -p $(dir $@)
	@printf "[$(GREEN)$(BOLD) OK $(RESET)] compiling $(BOLD)$@...$(RESET)$(CLEAR)"
	@$(CXX) -c $(CXXFLAGS) $< $(INCLUDES) -o $@

# --- Debug build ---
obj/debug/%.o: %.cpp
	@mkdir -p $(dir $@)
	@printf "[$(YELLOW)$(BOLD) DBG $(RESET)] compiling $(BOLD)$@...$(RESET)$(CLEAR)"
	@$(CXX) -c $(DBGFLAGS) $< $(INCLUDES) -o $@

clean:
	@printf "$(RED)$(BOLD)cleaning object files...\n$(RESET)"
	@rm -rf obj/

fclean: clean
	@printf "$(RED)$(BOLD)cleaning binary...\n$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all debug clean fclean re
