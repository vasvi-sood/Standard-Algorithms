Swithvhing with strings in C++ is not possible as it is not a standard type. 
However we can create a hash function from enums and switch to them instead:
<br>
Example

     enum string_code {
    eFred,
    eBarney,
    eWilma,
    eBetty,
    ...
    };

     string_code hashit (std::string const& inString) {
    if (inString == "Fred") return eFred;
    if (inString == "Barney") return eBarney;
    ...
    }

    void foo() {
    switch (hashit(stringValue)) {
    case eFred:
        ...
    case eBarney:
        ...
    }
    }

There are a bunch of obvious optimizations that pretty much follow what the C compiler would do with a switch statement... funny how that happens.
