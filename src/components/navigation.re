module Link = Gatsby.Link;

[@bs.module] external style : Js.t({..}) = "./navigation.module.scss";

open Util;

let component = ReasonReact.statelessComponent("Navigation");

type navigationLocation =
  | Header
  | Footer;

let make = (~pathName, ~navigationLocation=Header, _children) => {
  ...component,
  render: _self => {
    let isHomePage = pathName == "/";
    let rootClassName =
      switch (navigationLocation) {
      | Header => style##root_header
      | Footer => style##root_footer
      };
    /* We don't need active class named in the footer */
    let activeClassName =
      navigationLocation == Header ? Some(style##link_active) : None;
    /* Use link style for tickets link in the footer */
    let ticketsClassName =
      navigationLocation == Header ? Some(style##ticketsButton) : None;
    <nav className=rootClassName>
      (
        componentOrNull(
          ! isHomePage,
          <Link to_="/" className=style##link_home>
            <img src=Assets.logo alt="Home" className=style##logo />
          </Link>,
        )
      )
      <ul className=style##list>
        <li className=style##listItem>
          <Link to_="/schedule/#day3" className=style##link ?activeClassName>
            (s("Schedule"))
          </Link>
        </li>
        <li className=style##listItem>
          <Link to_="/speakers/" className=style##link ?activeClassName>
            (s("Speakers"))
          </Link>
        </li>
        <li className=style##listItem>
          <Link to_="/attendees/" className=style##link ?activeClassName>
            (s("For Attendees"))
          </Link>
        </li>
        <li className=style##listItem>
          <Link to_="/sponsors/" className=style##link ?activeClassName>
            (s("For Sponsors"))
          </Link>
        </li>
        <li className=style##listItem>
          <Link to_="/jobs/" className=style##link ?activeClassName>
            (s("Jobs"))
          </Link>
        </li>
        <li className=style##listItem>
          <Link to_="/about/" className=style##link ?activeClassName>
            (s("About"))
          </Link>
        </li>
        <li className=style##listItemBuy>
          <a
            href="https://ti.to/reason-conf/reason-conf-2018"
            target="_blank"
            className=?ticketsClassName>
            (s("Buy a ticket"))
          </a>
        </li>
      </ul>
    </nav>;
  },
};
