module helloworldfpga(input q0,q1,q2, output d0,d1,d2,cl);
reg d0=0,d1=0,d2=0 ;
reg[28:0] delay;
wire clk;
reg mclk;
qlal4s3b_cell_macro u_qlal4s3b_cell_macro (
        .Sys_Clk0 (clk),
    );
always @(posedge clk) begin
	delay=delay+1;
  if (delay>40000000) begin
     mclk=!mclk;
     delay=0;
  end
end
always @(negedge mclk) begin
  d2=q1;
  d1=q0;
  d0=!(q1||q2);
end
assign cl=mclk;
endmodule
