.PHONY: clean All

All:
	@echo "----------Building project:[ 03-MultiDeck - Debug ]----------"
	@cd "Blackjack-MultiDeck" && "$(MAKE)" -f  "03-MultiDeck.mk"
clean:
	@echo "----------Cleaning project:[ 03-MultiDeck - Debug ]----------"
	@cd "Blackjack-MultiDeck" && "$(MAKE)" -f  "03-MultiDeck.mk" clean
