# asl-playground
 
000-
  Edit layout to show how errors are reported
005-
  Explain that the other callbacks are about the Adam sheet built into Eve, and we're going to (mostly) ignore them today.
  Edit button with a property with some expression.
010-
  Walk through adding virtual machine and evaluate
020-
  Eve evaluate provides a bind_layout utitlity that will connect the parser to a VM, and
  property-model sheet, and takes a simplified callback for add_view where the parameters are
  preparsed into a dictionary.
  
  Now we can look at the parent argument - parent is a `std::any` - this is provided so the client
  can hold whatever information they want about the hierarchy. This is where you can put all the
  contextual properties to guide the layout!
