format 76

classinstance 128002 class_ref 130054 // Player
  name "Player1"   xyz 66.2 4 2000 life_line_z 2000
classinstance 128258 class_ref 129798 // Bomb
  name ""   xyz 452.7 3.8 2000 life_line_z 2000
classinstance 128386 class_ref 128646 // Ground
  name "map[x][y]"   xyz 221.8 3.8 2010 life_line_z 2025
classinstance 129410 class_ref 147842 // Timer
  name ""   xyz 682.7 3.8 2000 life_line_z 2000
note 130562 "Time elapsed"
  xyzwh 535.4 148.6 3005 122 35
classinstance 132482 class_ref 128774 // Fire
  name ""   xyz 354.2 5.2 2000 life_line_z 2000
note 137218 "Time elapsed"
  xyzwh 551.5 379.4 3005 122 35
note 138242 "Calls to onBurn() are not displayed"
  xyzwh 324.8 136.8 2000 116 53
durationcanvas 128642 classinstance_ref 128002 // Player1:Player
  xyzwh 101 50.4 2010 11 518
  overlappingdurationcanvas 129794
    xyzwh 107 122.2 2020 11 25
  end
  overlappingdurationcanvas 134914
    xyzwh 107 233.5 2020 11 25
  end
end
durationcanvas 128770 classinstance_ref 128386 // map[x][y]:Ground
  xyzwh 263 51.4 2035 11 515
end
durationcanvas 129026 classinstance_ref 128258 // :Bomb
  xyzwh 470 99.3 2010 11 206
  overlappingdurationcanvas 133634
    xyzwh 476 125.6 2020 11 34
  end
  overlappingdurationcanvas 134402
    xyzwh 476 216.2 2020 11 77
    overlappingdurationcanvas 134658
      xyzwh 482 229.2 2030 11 52
    end
  end
end
durationcanvas 129538 classinstance_ref 129410 // :Timer
  xyzwh 700 50.3 2010 11 524
  overlappingdurationcanvas 133378
    xyzwh 706 131.9 2020 11 25
  end
  overlappingdurationcanvas 133890
    xyzwh 706 209.3 2020 11 25
  end
  overlappingdurationcanvas 136450
    xyzwh 706 326.4 2020 11 25
  end
  overlappingdurationcanvas 136706
    xyzwh 706 360.6 2020 11 25
  end
  overlappingdurationcanvas 137346
    xyzwh 706 420.6 2020 11 25
  end
end
durationcanvas 136194 classinstance_ref 132482 // :Fire
  xyzwh 373 264.2 2010 11 222
  overlappingdurationcanvas 136962
    xyzwh 379 366.4 2020 11 26
  end
  overlappingdurationcanvas 137602
    xyzwh 379 425.4 2020 11 48
    overlappingdurationcanvas 137858
      xyzwh 385 442.2 2030 11 25
    end
  end
end
msg 128898 synchronous
  from durationcanvas_ref 128642
  to durationcanvas_ref 128770
  yz 87 2015 msg operation_ref 148994 // "placeBomb()"
  show_full_operations_definition default drawing_language default show_context_mode default
  label_xy 141 72
msg 129154 synchronous
  from durationcanvas_ref 128770
  to durationcanvas_ref 129026
  yz 100 2015 explicitmsg "Bomb()"
  show_full_operations_definition default drawing_language default show_context_mode default
  label_xy 305 87
msg 129666 synchronous
  from durationcanvas_ref 129026
  to durationcanvas_ref 129538
  yz 113 2020 msg operation_ref 148482 // "attach()"
  show_full_operations_definition default drawing_language default show_context_mode default
  label_xy 539 99
reflexivemsg 129922 synchronous
  to durationcanvas_ref 129794
  yz 122 2025 explicitmsg "decrease bombCounter"
  show_full_operations_definition default drawing_language default show_context_mode default
  label_xy 135 119
msg 132354 return
  from durationcanvas_ref 129026
  to durationcanvas_ref 129538
  yz 295 2015 explicitmsg "die"
  show_full_operations_definition default drawing_language default show_context_mode default
  label_xy 554 284
reflexivemsg 133506 synchronous
  to durationcanvas_ref 133378
  yz 131 2025 msg operation_ref 148354 // "masterTick()"
  show_full_operations_definition default drawing_language default show_context_mode default
  label_xy 737 128
msg 133762 synchronous
  from durationcanvas_ref 133378
  to durationcanvas_ref 133634
  yz 130 2030 msg operation_ref 148226 // "tick()"
  show_full_operations_definition default drawing_language default show_context_mode default
  label_xy 559 119
reflexivemsg 134018 synchronous
  to durationcanvas_ref 133890
  yz 209 2025 msg operation_ref 148354 // "masterTick()"
  show_full_operations_definition default drawing_language default show_context_mode default
  label_xy 735 205
msg 134530 synchronous
  from durationcanvas_ref 133890
  to durationcanvas_ref 134402
  yz 215 2030 msg operation_ref 148226 // "tick()"
  show_full_operations_definition default drawing_language default show_context_mode default
  label_xy 559 203
reflexivemsg 134786 synchronous
  to durationcanvas_ref 134658
  yz 229 2035 msg operation_ref 148738 // "expire()"
  show_full_operations_definition default drawing_language default show_context_mode default
  label_xy 512 226
msg 135042 synchronous
  from durationcanvas_ref 134658
  to durationcanvas_ref 134914
  yz 233 2040 explicitmsg "decrease bombCounter"
  show_full_operations_definition default drawing_language default show_context_mode default
  label_xy 136 223
msg 136322 synchronous
  from durationcanvas_ref 134658
  to durationcanvas_ref 136194
  yz 264 2035 explicitmsg "Fire()"
  show_full_operations_definition default drawing_language default show_context_mode default
  label_xy 417 252
msg 136578 synchronous
  from durationcanvas_ref 136194
  to durationcanvas_ref 136450
  yz 327 2025 msg operation_ref 148482 // "attach()"
  show_full_operations_definition default drawing_language default show_context_mode default
  label_xy 583 316
reflexivemsg 136834 synchronous
  to durationcanvas_ref 136706
  yz 360 2025 msg operation_ref 148354 // "masterTick()"
  show_full_operations_definition default drawing_language default show_context_mode default
  label_xy 736 357
msg 137090 synchronous
  from durationcanvas_ref 136706
  to durationcanvas_ref 136962
  yz 366 2030 msg operation_ref 148226 // "tick()"
  show_full_operations_definition default drawing_language default show_context_mode default
  label_xy 591 355
reflexivemsg 137474 synchronous
  to durationcanvas_ref 137346
  yz 420 2025 msg operation_ref 148354 // "masterTick()"
  show_full_operations_definition default drawing_language default show_context_mode default
  label_xy 737 418
msg 137730 synchronous
  from durationcanvas_ref 137346
  to durationcanvas_ref 137602
  yz 430 2030 msg operation_ref 148226 // "tick()"
  show_full_operations_definition default drawing_language default show_context_mode default
  label_xy 590 419
reflexivemsg 137986 synchronous
  to durationcanvas_ref 137858
  yz 442 2035 msg operation_ref 148738 // "expire()"
  show_full_operations_definition default drawing_language default show_context_mode default
  label_xy 413 439
msg 138114 return
  from durationcanvas_ref 136194
  to durationcanvas_ref 129538
  yz 473 2025 explicitmsg "die"
  show_full_operations_definition default drawing_language default show_context_mode default
  label_xy 529 462
end
