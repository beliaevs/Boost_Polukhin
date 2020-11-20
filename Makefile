ALL = options any_variant
.PHONY: all $(ALL)

all: $(ALL)

$(ALL):
	cd $@; $(MAKE); cd ..

clean:
	for d in $(ALL); do \
		(cd $$d; $(MAKE) clean; cd ..);\
	done

