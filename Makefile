all :
	@make -C src/push_swap/
	@make -C src/checker/

clean :
	@make clean -C src/checker/
	@make clean -C src/push_swap/

fclean : clean
	@make fclean -C src/push_swap/
	@make fclean -C src/checker/

re : fclean all
