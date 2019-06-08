all :
	@make -C src/checker/
	@make -C src/push_swap/

clean :
	@make clean -C src/checker/
	@make clean -C src/push_swap/

fclean : clean
	@make fclean -C src/checker/
	@make fclean -C src/push_swap/

re : fclean all
