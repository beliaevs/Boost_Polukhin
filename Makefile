options_:
	cd options; make; cd ..

any_variant_:
	cd any_variant; make; cd ..

all: options_ any_variant_
	echo "making all"

clean:
	cd options; make clean; cd ../any_variant; make clean; cd ..


