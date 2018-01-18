module Link = Gatsby.Link;

[@bs.module] external style : Js.t({..}) = "./subscribeForm.module.scss";

let component = ReasonReact.statelessComponent("SubscribeForm");

let s = ReasonReact.stringToElement;

let make = _children => {
  ...component,
  render: _self =>
    ReasonReact.cloneElement(
      <form name="newsletter" action="/" className=style##root>
        <p className=style##text>
          (
            s(
              "Get Reason Conf news straight to your inbox. No spam, we promise!"
            )
          )
        </p>
        <div className=style##formRow>
          <label htmlFor="email" className=style##label>
            (s("Email: "))
          </label>
          <input
            _type="email"
            name="email"
            id="email"
            placeholder="name@domain.com"
            className=style##input
          />
          <Button _type="submit"> (s("Subscribe")) </Button>
        </div>
      </form>,
      ~props={"data-netlify": Js.true_},
      [||]
    )
};